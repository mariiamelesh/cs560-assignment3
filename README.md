
### Class Hierarchy
The architecture isolates cipher algorithms from the consumer environment through a decoupled hierarchy:
`cipher`: basically an API contract. It contains no structural state fields, declares two pure virtual functions, `encrypt()` and `decrypt()`  
`caesarCipher`: innherits  `cipher`; implements Caesar cipher  
`vigenereCipher`: inherits from `cipher`; implements Vigenere's cipher  
`affineCipher`: Inherits from `cipher`; implements Affine's cipher  
<img width="1269" height="440" alt="image" src="https://github.com/user-attachments/assets/990652c7-f126-4a21-a7ec-1271381a5034" />

