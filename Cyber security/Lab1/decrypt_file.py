import base64
from cryptography.hazmat.primitives import hashes, hmac

from enc_ctr import dec_ctr
from password import gen_key

INPUT_FILE = "data_enc.txt"
OUTPUT_FILE = "data_dec.txt"

# Verify the HMAC
def verify_mac(mac_key, plaintext, received_mac):
    # Create a new HMAC object using the HMAC key.
    h = hmac.HMAC(mac_key, hashes.SHA256())

    # Calculate the HMAC of the decrypted plaintext.
    h.update(plaintext)

    try:
        # Compare the calculated HMAC with the received HMAC.
        h.verify(received_mac)
        return True

    except Exception:
        # The MACs did not match.
        return False

# ---------------------------------------------------------
# Main program for the decrypt_file script
# ---------------------------------------------------------
def main():
# Read the Base64 encoded data from the input file.
    with open(INPUT_FILE, "rb") as file:
        encoded_data = file.read()

    # Convert the Base64 encoded data back into binary byte array.
    data = base64.b64decode(encoded_data)

    salt = data[:16] # The first 16 bytes are the seed used for key derivation.

    received_mac = data[-32:] # The last 32 bytes are the HMAC.

    iv_ciphertext = data[16:-32] # Everything between the salt and HMAC is IV + ciphertext

    # Returned tuple with key and seed.
    sk_tuple = gen_key(salt)
    key = sk_tuple[1] #first item is key    

    # Split the 256-bit key into two 128-bit keys
    encryption_key = key[:16] # First 16 bytes for AES encryption key.
    mac_key = key[16:]# Last 16 bytes for HMAC key.

    # Decrypt the ciphertext
    try:
        plaintext = dec_ctr(encryption_key, iv_ciphertext)

    except Exception:
        print("Error: Decryption failed.")
        exit()

    # Verify the message authentication code
    if verify_mac(mac_key, plaintext, received_mac):
        # The HMAC is valid, so the plaintext can safely be saved.
        with open(OUTPUT_FILE, "wb") as file:
            file.write(plaintext)

        print("Decryption successful.")
        print(f"Plaintext saved to {OUTPUT_FILE}")

    else:
        print("Error: Message authentication code is invalid.")
        print("The password may be incorrect or the data has been modified.")

if __name__ == "__main__":
    main()
