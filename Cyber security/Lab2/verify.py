from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding

PUBLIC_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\myPublic.pem"
DATA_SIGN_fILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\data.txt.sig"

def main():
    with open(PUBLIC_FILE, "rb") as key_file:
        public_key = serialization.load_pem_public_key(
            key_file.read() # Load the public key
        )
    # Read datafile and signature
    with open(DATA_SIGN_fILE, "rb") as sign_file:
        datafile_signature = sign_file.read()

    # Split the datafile and signature
    datafile = datafile_signature[:-256]
    signature = datafile_signature[-256:]

    datafil = datafile.decode("utf-8") # Data file from bytes to string 

    with open(datafil, "rb") as sign_file:
        message = sign_file.read() # Read data from file as bytes
    
    message2 = "This is modified msg.".encode()
    try:
        # Check that private key associated with public key was used to sign the message
        public_key.verify(
            signature,
            message, #The message to be verified
            padding.PSS( # Specify the signing algorithm used 
                mgf=padding.MGF1(hashes.SHA256()),
                salt_length=padding.PSS.MAX_LENGTH
            ),
            hashes.SHA256()
        )
        print("\n==== Signature verification successful. ====")

    except Exception:
        print("\n==== Signature verification failed. ====")

if __name__ == "__main__":
    main()