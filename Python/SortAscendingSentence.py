# Menginput Kalimat
kalimat = input("Tulis Sebuah Kalimat: ")
 
# Memecah Kalimat menjadi Kata-Kata
kata = kalimat.split()
 
# Mengurutkan Kata-Kata
kata.sort()
 
# Menampilkan Kata-Kata yang Telah Diurutkan
print("Berikut Urutan Kata-Kata:")
for urut in kata:
   print(urut)