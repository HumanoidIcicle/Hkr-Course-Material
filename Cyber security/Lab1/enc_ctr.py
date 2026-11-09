import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

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

def dec_ctr(key, ciphertext):
    iv = ciphertext[:16] # Slice and get iv as the first 16 bytes
    encrypted = ciphertext[16:] # Get the rest bytes that are ciphertext

    cipher = Cipher(algorithms.AES(key), modes.CTR(iv))

    # Decryptor object
    decryptor = cipher.decryptor() 

    # Start and finish the decryption
    text = decryptor.update(encrypted) + decryptor.finalize()

    return text # return the original msg

def main():
    key = os.urandom(16)
    msg = input("\nMessage: ")
    msg = msg.encode()

    iv_ct = enc_ctr(key, msg)

    print("\nEncrypted: ")
    print(iv_ct)
    print("\nDecrypted: ")
    print(dec_ctr(key, iv_ct))


if __name__ == "__main__":
    main()
