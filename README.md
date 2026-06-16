# REPORT: Caesars, Vigeneres and Affines ciphers
## Topic
Encryption Algorithms: Object-Oriented Programming
## Purpose of work
Encryption is the process of transforming readable data (plaintext) into an unreadable form
(ciphertext) using a secret key, so only authorized parties can recover the original message. Unlike
encoding — which is a reversible, publicly known transformation with no secret (e.g. Base64 or
UTF-8) — encryption is designed to keep data confidential.
Gain experience in object-oriented programming by building a cipher library in C++. Apply the
core OOP principles — encapsulation, inheritance, and polymorphism — through a practical
implementation. Learn how to design a clean public API for a C++ dynamic library that remains
stable across compilers and platforms.
### Class Hierarchy
The architecture isolates cipher algorithms from the consumer environment through a decoupled hierarchy:
`cipher`: basically an API contract. It contains no structural state fields, declares two pure virtual functions, `encrypt()` and `decrypt()`  
`caesarCipher`: innherits  `cipher`; implements Caesar cipher  
`vigenereCipher`: inherits from `cipher`; implements Vigenere's cipher  
`affineCipher`: Inherits from `cipher`; implements Affine's cipher  
<img width="1269" height="440" alt="image" src="https://github.com/user-attachments/assets/990652c7-f126-4a21-a7ec-1271381a5034" />
### Test plan
- caesar encryption with simple key and text
<img width="588" height="274" alt="image" src="https://github.com/user-attachments/assets/384f4825-cae5-47c3-a604-57c9cd568202" />
- caesar decryption
<img width="588" height="244" alt="image" src="https://github.com/user-attachments/assets/591bd32c-038b-489e-bbe0-a80e2bdfc7f8" />
- vigenere encryption with simple key and text
<img width="602" height="276" alt="image" src="https://github.com/user-attachments/assets/0f955623-74b7-4955-8b4a-cfbf1c561345" />
- vigenere decryption
 <img width="583" height="249" alt="image" src="https://github.com/user-attachments/assets/67f58973-71a9-4390-a4c0-5b3aac05c308" />
- library loads at runtime
<img width="576" height="290" alt="image" src="https://github.com/user-attachments/assets/02177b5c-6751-4c87-a34f-feb3d64e59b4" />
- correct wrap at the end of alphabet
<img width="560" height="239" alt="image" src="https://github.com/user-attachments/assets/4cb51adc-9fb5-4e29-8c18-03b8cb1c0169" />
