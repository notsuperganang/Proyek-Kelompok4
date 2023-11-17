# Proyek Kelompok 4 (Permainan Who Wants To Be A Millionaire)

## Gambaran

Repositori ini berisi implementasi sederhana permainan "Who Wants To Be A Millionaire" dalam bahasa pemrograman C. Permainan ini mengajukan serangkaian pertanyaan pilihan ganda, dan pemain dapat memenangkan hadiah besar sebanyak 1 juta dolar dengan menjawab semua pertanyaan dengan benar. Program ini mencakup pembuatan akun, fungsionalitas login, dan aturan dasar permainan.

## Cara Menggunakan

### Prasyarat

- Pastikan Anda memiliki kompiler C terpasang di sistem Anda.
- Klon repositori ini ke mesin lokal Anda.

### Kompilasi

Kompilasi program menggunakan perintah berikut:

```bash
gcc main.c -o main
```

### Menjalankan Program

#### Pembuatan Akun

Untuk membuat akun, jalankan perintah berikut:

```bash
./main
```

Ikuti petunjuk di layar untuk memasukkan nama pengguna dan kata sandi Anda.

#### Login

Untuk login, jalankan perintah berikut:

```bash
./main <nama_pengguna> <kata_sandi>
```

Gantilah `<nama_pengguna>` dan `<kata_sandi>` dengan rincian akun Anda.

#### Memainkan Permainan

Setelah berhasil login, Anda akan diperlihatkan dengan menu utama. Pilih opsi 1 untuk mulai memainkan permainan. Jawablah pertanyaan dengan memasukkan nomor yang sesuai (1-4). Permainan akan memberikan umpan balik untuk setiap jawaban, dan Anda dapat memutuskan apakah ingin melanjutkan atau berhenti setelah setiap pertanyaan.

#### Aturan dan FAQ

Anda dapat mengakses aturan permainan dan pertanyaan yang sering diajukan dengan memilih opsi 2 dan 3 dari menu utama, secara berturut-turut.

### Lisensi

Proyek ini dilisensikan di bawah [Lisensi MIT](LICENSE).
