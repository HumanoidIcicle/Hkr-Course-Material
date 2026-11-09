import os
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes


PUBLIC_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\myPublic.pem"
ENCRYPTED_DATA_IV = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt.enc"
ENCRYPTED_KEY = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt.key"

def enc_ctr(key, plaintext):
    #generate 128bit iv
    iv = os.urandom(16)

    #Create a cipher object using AES algorithm in CTR mode
    ciphertext = Cipher(algorithms.AES(key), modes.CTR(iv))

    #Encryptor object
    encryptor = ciphertext.encryptor();

    #Process plaintext and complete encryption
    ct = encryptor.update(plaintext) + encryptor.finalize()

    #Return the iv and ciphertext
    return iv + ct 

def main():
    with open(PUBLIC_FILE, "rb") as key_file:
        public_key = serialization.load_pem_public_key(
            key_file.read() # Load the public key
        )

    input_file = input("Enter file to encrypt: ")
    with open(input_file, "rb") as file:
        plaintext = file.read() # Get the data to encrypt

    session_key = os.urandom(16) # Random Session key
    #print(f"\nLen of data: {len(plaintext)}")
    #print(f"\nLen of session key: {len(session_key)}")
    iv_ciphertext = enc_ctr(session_key,plaintext)

    # Save iv and encrypted data
    with open(ENCRYPTED_DATA_IV, "wb") as file:
            file.write(iv_ciphertext)
    print(f"\n==== Saved iv + ciphertext to {ENCRYPTED_DATA_IV} ====")

    #Encrypt session key with RSA encryption
    enc_sesh_key = public_key.encrypt(
        session_key,
        padding.OAEP( # Padding algorithm
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    # Save encrypted session key
    with open(ENCRYPTED_KEY, "wb") as file:
            file.write(enc_sesh_key)
    print(f"\n==== Saved seesion key to {ENCRYPTED_KEY} ====")

    #print(f"\nLen of encrypted key: {len(enc_sesh_key)}")
    #print(f"\nLen of public key: {public_key.key_size}")

if __name__ == "__main__":
    main()
