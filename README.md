# Criptografia

Encrypt and or decrypt files easily.

## Questions:

### Is it safe?
I dont know for sure, but I think it is. Just get a long key.

### How does it works?
It is just a XOR cypher. Im gonna add more stuff out later.

## Return codes (AKA exit codes):
Returns 0 on success;
When something goes wrong (and the application doesnt crash), one of the following codes is going to be returned:

| Code | Reason                      |
|------|-----------------------------|
| -1   | Could not open input file.  |
| 1    | Could not open output file. |