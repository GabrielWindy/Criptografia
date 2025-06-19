# Criptografia

Encrypt and or decrypt files easily.

## Usage:
criptografia.exe < file > < keyString > < mode > [ output location ]

**file**: Input file.
**keyString**: Key.
**mode**: The mode to encrypt the input file.
**output location**: Place to put the output of the encryption.

### Modes:
- xor_crypt
- xor_decrypt_
## Questions:

### Is it safe?
Nuh uh. Use this at your own risk. Im a begginer at programming and you will most likely get hacked if you use it.

### Do I plan on making it usable and better?
Of course yes! I imagine it would make me a better programmer. If you find any issues, you are more than welcome to report them!

### How does it works?
It is just a XOR cypher. Im gonna add more stuff out later.

## Return codes (AKA exit codes):
Returns 0 on success;
When something goes wrong (and the application doesnt crash), one of the following codes is going to be returned:

| Code | Reason                      |
|------|-----------------------------|
| -1   | Could not open input file.  |
| 1    | Could not open output file. |