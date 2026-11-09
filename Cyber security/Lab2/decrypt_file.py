from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

ENCRYPTED_DATA_IV = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt.enc"
ENCRYPTED_KEY = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt.key"
PRIVATE_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\myPrivate.pem"
OUTPUT_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt.dec"

def dec_ctr(key, iv_ciphertext):
    iv = iv_ciphertext[:16] # Slice and get iv as the first 16 bytes
    encrypted = iv_ciphertext[16:] # Get the rest bytes that are ciphertext

    cipher = Cipher(algorithms.AES(key), modes.CTR(iv))

    # Decryptor object
    decryptor = cipher.decryptor() 

    # Start and finish the decryption
    text = decryptor.update(encrypted) + decryptor.finalize()

    return text # return the original msg

def main():
    password = input("Enter password: ")
    password = password.encode()

    # Load the private key
    with open(PRIVATE_FILE, "rb") as key_file:
        priv_key = serialization.load_pem_private_key(
            key_file.read(), # Load the private key
            password=password
        )
    
    # Load the encrypted session key
    with open(ENCRYPTED_KEY, "rb") as key_file:
        enc_session_key = key_file.read() # Load the encrypted session key

    # Decrypt the session key with RSA
    dec_session_key = priv_key.decrypt(
        enc_session_key,
        padding.OAEP( # Same parameters as encrypt
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    # Get the data to encrypt
    with open(ENCRYPTED_DATA_IV, "rb") as file:
        iv_ciphertext = file.read() 

    #Decrypt the ciphertext
    plaintext = dec_ctr(dec_session_key, iv_ciphertext)

    #Save the plaintext to file
    with open(OUTPUT_FILE, "wb") as file:
        file.write(plaintext)

    print("\n==== Data decrypted successfully. ====")
    print(f"\n==== Saved plaintext message to {OUTPUT_FILE} ====")

    
if __name__ == "__main__":
    main()