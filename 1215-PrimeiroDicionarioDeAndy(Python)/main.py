# João Victor Alves Cerqueira - 01/10/2021
x = []
for i in range(10000):
    try:
        frase = input()
        for caracteres in frase:
            if not caracteres.isalpha() or not caracteres.isascii():
                frase = frase.replace(caracteres," ")
        x += frase.lower().split()
    except EOFError:
        break
dic = sorted(list(set(x)))
for i in dic:
    print(i)