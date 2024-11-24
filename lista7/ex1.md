Para buscar um elemento com uma dada chave em uma lista ligada de comprimento \( n \), podemos usar os valores de hash da seguinte forma:  

1. **Calcule o hash da chave buscada**:  
   Determine o valor de \( h(k) \) para a chave.  

2. **Compare os hashes durante a iteração**:  
   - Para cada elemento, compare o valor de \( h(k) \) com o hash armazenado \( h(k') \).  
   - **Se os hashes forem diferentes**, descarte o elemento sem realizar a comparação completa da chave.  
   - **Se os hashes forem iguais**, realize a comparação completa das chaves para verificar se são iguais.  

