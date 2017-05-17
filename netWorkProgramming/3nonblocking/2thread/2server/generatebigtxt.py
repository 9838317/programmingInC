a = open("txt", "w")

for i in range(1000000):
    a.write("qweasdzxcrtyfghvbnuiojklm." + str(i))
a.close()
