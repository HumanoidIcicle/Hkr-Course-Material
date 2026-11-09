from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding

DATA_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt"

PRIVATE_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\myPrivate.pem"
DATA_SIGN_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt.sig"

def main():
    password = input("Enter password: ")
    password = password.encode()
    data_file = input("Enter file to sign: ")

    # Load the private key
    with open(PRIVATE_FILE, "rb") as key_file:
        private_key = serialization.load_pem_private_key(
            key_file.read(),
            password=password,  # Decrypt the private key using the password
        )

    # Open the file to be signed
    with open(data_file, "rb") as file:
        plaintext = file.read()  # Read the file as bytes

    # Create a digital signature using the private key
    signature = private_key.sign(
        plaintext,
        padding.PSS( # Use RSA-PSS padding for the signature
            # MGF1 is the mask generation function used by RSA-PSS
            mgf=padding.MGF1(hashes.SHA256()),

            # Let the cryptography library choose the maximum salt length
            salt_length=padding.PSS.MAX_LENGTH
        ),
        hashes.SHA256() # SHA-256 is used to create a hash of the data before signing
    )
    # Combine the filename and signature into one byte sequence
    save = DATA_FILE.encode() + signature

    # Save the filename and signature to the output file
    with open(DATA_SIGN_FILE, "wb") as file:
        file.write(save)
    print("\n==== Digital signature created. ====")
    print(f"\n==== Saved to {DATA_SIGN_FILE} ====")
    
if __name__ == "__main__":
    main()
