import base64
import os

from cryptography.hazmat.primitives import hashes, hmac

from enc_ctr import enc_ctr
from password import gen_key

INPUT_FILE = "data.txt"
OUTPUT_FILE = "data_enc.txt"

def generate_mac(mac_key, plaintext):
    # Calculate an HMAC-SHA256 over the original plaintext.
    h = hmac.HMAC(mac_key, hashes.SHA256())
    h.update(plaintext)

    return h.finalize()

# ---------------------------------------------------------
# Main program for the encrypt_file
# ---------------------------------------------------------
def main():
    # Read the plaintext.
    with open(INPUT_FILE, "rb") as file:
        plaintext = file.read()

    salt = os.urandom(16)

    # Returned tuple with key and seed.
    sk_tuple = gen_key(salt)
    
    seed =sk_tuple[0] #first item is seed
    key = sk_tuple[1] #second item is key

    # Split the 256-bit key into two 128-bit keys.
    encryption_key = key[:16]
    mac_key = key[16:]
    
    # Encrypt the plaintext.
    iv_ciphertext = enc_ctr(encryption_key, plaintext)

    # Authenticate the original plaintext.
    mac = generate_mac(mac_key, plaintext)

    # Final structure:
    # [16-byte seed][16-byte IV + ciphertext][32-byte HMAC]
    output_data = seed + iv_ciphertext + mac

    # Encode the binary data as Base64.
    encoded_data = base64.b64encode(output_data)

    # Save the encrypted data.
    with open(OUTPUT_FILE, "wb") as file:
        file.write(encoded_data)

    print("Encryption complete.")
    print(f"Encrypted data saved to {OUTPUT_FILE}")

if __name__ == "__main__":
    main()
