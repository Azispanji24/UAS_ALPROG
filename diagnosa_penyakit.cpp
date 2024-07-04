#include <iostream>
#include <string>

using namespace std;

struct Penyakit
{
    string gejala[5];
    string nama;
    string solusi;
    string obat;
    string saranObat;
    string laranganMakanan;
    string tindakanDokter;
    string tindakanKhusus;
};

void cariPenyakit(Penyakit *daftarPenyakit, int jumlahPenyakit, const string &keluhanSatu, const string &keluhanDua, const string &keluhanTiga)
{
    bool ditemukan = false;
    for (int i = 0; i < jumlahPenyakit; i++)
    {
        bool gejalaPertamaDitemukan = false;
        bool gejalaKeduaDitemukan = false;
        bool gejalaKetigaDitemukan = false;

        for (const auto &gejala : daftarPenyakit[i].gejala)
        {
            if (gejala.find(keluhanSatu) != string::npos || daftarPenyakit[i].nama.find(keluhanSatu) != string::npos)
            {
                gejalaPertamaDitemukan = true;
            }
            if (gejala.find(keluhanDua) != string::npos || daftarPenyakit[i].nama.find(keluhanDua) != string::npos)
            {
                gejalaKeduaDitemukan = true;
            }
            if (gejala.find(keluhanTiga) != string::npos || daftarPenyakit[i].nama.find(keluhanTiga) != string::npos)
            {
                gejalaKetigaDitemukan = true;
            }
        }

        if (gejalaPertamaDitemukan && gejalaKeduaDitemukan && gejalaKetigaDitemukan)
        {
            cout << "-------------------------------------------------------" << endl;
            cout << "Penyakit : " << daftarPenyakit[i].nama << endl;
            cout << "Gejala   : " << daftarPenyakit[i].gejala[0] << ", " << daftarPenyakit[i].gejala[1] << ", " << daftarPenyakit[i].gejala[2] << ", " << daftarPenyakit[i].gejala[3] << ", " << daftarPenyakit[i].gejala[4] << endl;
            cout << "Solusi   : " << daftarPenyakit[i].solusi << endl;
            cout << "Obat     : konsumsi kandungan " << daftarPenyakit[i].obat << endl;
            cout << "saran Obat : " << daftarPenyakit[i].saranObat << endl;
            if (!daftarPenyakit[i].laranganMakanan.empty())
            {
                cout << "Larangan Makanan: " << daftarPenyakit[i].laranganMakanan << endl;
            }
            if (!daftarPenyakit[i].tindakanDokter.empty())
            {
                cout << "Tindakan : " << daftarPenyakit[i].tindakanDokter << endl;
            }
            if (!daftarPenyakit[i].tindakanKhusus.empty())
            {
                cout << "Tindakan khusus : " << daftarPenyakit[i].tindakanDokter << endl;
            }
            cout << "Untuk obat gunakan resep dokter!" << endl;
            cout << "------------------ Diagnosa Penyakit ------------------" << endl;
            cout << "=======================================================" << endl
                 << endl
                 << endl;

            ditemukan = true;
        }
    }
    if (!ditemukan)
    {
        cout << "Maaf, tidak ditemukan penyakit yang cocok dengan keluhan Anda." << endl;
    }
}

void cariPenyakit(Penyakit *daftarPenyakit, int jumlahPenyakit, const string &obatpasien)
{
    bool ditemukan = false;
    for (int i = 0; i < jumlahPenyakit; i++)
    {

        if (daftarPenyakit[i].nama == obatpasien)
        {
            // gejalaPertamaDitemukan = true;
            bool ditemukan = false;
            cout << "-------------------------------------------------------" << endl;
            cout << "obat : " << daftarPenyakit[i].obat << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Maaf, tidak ditemukan penyakit yang cocok dengan keluhan Anda." << endl;
    }
}

int main()
{
    const int jumlahPenyakit = 202;

    Penyakit daftarPenyakit[jumlahPenyakit] = {
        {{"sakit perut bagian kiri", "mual", "kembung", "sakit tenggorokan", "sulit menelan"},
         "sakit lambung",
         "Menghindari makanan pedas dan asam, makan secara teratur",
         "Antasida, Omeprazole",
         "Antasida atau Omeprazole",
         "makanan pedas, makanan asam",
         "makanan tinggi serat, sayuran hijau",
         ""},
        {{"demam", "nyeri otot", "sakit kepala", "mimisan", "nyeri otot"},
         "demam berdarah",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, minum cairan elektrolit",
         "Paracetamol atau cairan elektrolit",
         "makanan berminyak",
         "buah-buahan, sayuran segar",
         ""},

        {{"batuk", "demam", "sakit kepala", "nyeri tenggorokan", "kelelahan"},
         "flu",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Ibuprofen",
         "Paracetamol atau Ibuprofen",
         "makanan berminyak, minuman dingin",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri sendi", "kaku sendi", "bengkak sendi", "kemerahan", "sulit bergerak"},
         "artritis",
         "Fisioterapi, obat antiinflamasi",
         "Ibuprofen, Naproxen",
         "Ibuprofen atau Naproxen",
         "makanan tinggi purin",
         "buah-buahan, sayuran segar",
         ""},
        {{"sakit kepala", "mual", "muntah", "sensitivitas cahaya", "penglihatan kabur"},
         "migrain",
         "Istirahat di ruangan gelap, minum banyak cairan",
         "Triptan, NSAID",
         "Triptan atau NSAID",
         "makanan berminyak, minuman beralkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"sulit tidur", "cepat marah", "kelelahan", "gangguan konsentrasi", "sakit kepala"},
         "insomnia",
         "Menjaga rutinitas tidur, hindari kafein",
         "Melatonin, Difenhidramin",
         "Melatonin atau Difenhidramin",
         "kafein, alkohol",
         "makanan ringan sebelum tidur",
         ""},
        {{"sesak napas", "batuk berdahak", "demam", "nyeri dada", "kelelahan"},
         "pneumonia",
         "Antibiotik, istirahat yang cukup",
         "Amoksisilin, Azitromisin",
         "Amoksisilin atau Azitromisin",
         "rokok, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"gatal-gatal", "ruam merah", "bengkak", "nyeri", "demam"},
         "alergi",
         "Hindari alergen, gunakan antihistamin",
         "Loratadin, Cetirizine",
         "Loratadin atau Cetirizine",
         "makanan pemicu alergi",
         "buah-buahan, sayuran segar",
         ""},
        {{"perut kembung", "nyeri perut", "diare", "mual", "muntah"},
         "gastroenteritis",
         "Istirahat yang cukup, minum banyak cairan",
         "Oralit, Loperamide",
         "Oralit atau Loperamide",
         "makanan pedas, makanan berminyak",
         "buah-buahan, sayuran segar",
         ""},

        {{"sakit tenggorokan", "demam", "nyeri menelan", "kelenjar bengkak", "sakit kepala"},
         "radang tenggorokan",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Ibuprofen",
         "Paracetamol atau Ibuprofen",
         "makanan pedas, minuman dingin",
         "buah-buahan, sayuran segar",
         ""},
        {{"keringat berlebih", "rasa haus berlebihan", "frekuensi buang air kecil meningkat", "kelelahan", "penurunan berat badan"},
         "diabetes",
         "Kontrol gula darah, diet sehat",
         "Metformin, Insulin",
         "Metformin atau Insulin",
         "makanan tinggi gula",
         "sayuran hijau, biji-bijian",
         ""},
        {{"sakit perut", "kembung", "diare", "mual", "nyeri perut bagian bawah"},
         "sindrom iritasi usus",
         "Diet rendah FODMAP, manajemen stres",
         "Antispasmodik, Probiotik",
         "Antispasmodik atau Probiotik",
         "makanan pedas, makanan berminyak",
         "buah-buahan, sayuran segar",
         ""},
        {{"gatal di area genital", "rasa terbakar saat buang air kecil", "keputihan tidak normal", "nyeri saat berhubungan seksual", "kemerahan"},
         "infeksi jamur",
         "Gunakan krim antijamur, jaga kebersihan",
         "Mikonazol, Clotrimazole",
         "Mikonazol atau Clotrimazole",
         "pakaian ketat, bahan sintetis",
         "makanan rendah gula",
         ""},
        {{"nyeri perut bagian kanan atas", "mual", "muntah", "demam", "kulit dan mata menguning"},
         "hepatitis",
         "Istirahat yang cukup, minum banyak cairan",
         "Antiviral, interferon",
         "Antiviral atau interferon",
         "alkohol, makanan berlemak",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri sendi", "bengkak sendi", "kemerahan", "panas di sekitar sendi", "sulit bergerak"},
         "asam urat",
         "Hindari makanan tinggi purin, minum banyak air",
         "Allopurinol, Colchicine",
         "Allopurinol atau Colchicine",
         "makanan tinggi purin, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"batuk kronis", "sesak napas", "produksi dahak berlebih", "nyeri dada", "kelelahan"},
         "bronkitis",
         "Hindari rokok, minum banyak cairan",
         "Antibiotik, Bronkodilator",
         "Antibiotik atau Bronkodilator",
         "rokok, polusi udara",
         "buah-buahan, sayuran segar",
         ""},
        {{"pusing", "mual", "muntah", "sensitivitas terhadap cahaya", "penglihatan kabur"},
         "vertigo",
         "Istirahat, minum obat yang diresepkan",
         "Betahistine, Meclizine",
         "Betahistine atau Meclizine",
         "makanan tinggi garam, kafein",
         "buah-buahan, sayuran segar",
         ""},
        {{"kulit kemerahan", "gatal-gatal", "ruam", "kulit kering", "bengkak"},
         "eksim",
         "Gunakan krim pelembap, hindari iritasi",
         "Kortikosteroid topikal, Antihistamin",
         "Kortikosteroid atau Antihistamin",
         "sabun keras, bahan sintetis",
         "makanan rendah alergen",
         ""},
        {{"nyeri dada", "sesak napas", "kelelahan", "berkeringat dingin", "mual"},
         "serangan jantung",
         "Segera ke rumah sakit, minum obat yang diresepkan",
         "Aspirin, Nitroglycerin",
         "Aspirin atau Nitroglycerin",
         "makanan tinggi lemak, garam",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri punggung bawah", "kaku punggung", "kram otot", "kesemutan", "kelemahan"},
         "nyeri punggung bawah",
         "Fisioterapi, istirahat yang cukup",
         "NSAID, Relaksan otot",
         "NSAID atau Relaksan otot",
         "aktivitas berat, posisi duduk salah",
         "makanan tinggi kalsium",
         ""},
        {{"kembung", "diare", "nyeri perut", "mual", "muntah"},
         "intoleransi laktosa",
         "Hindari produk susu, gunakan enzim laktase",
         "Enzim laktase, Probiotik",
         "Enzim laktase atau Probiotik",
         "produk susu",
         "alternatif bebas laktosa",
         ""},
        {{"kehilangan berat badan tanpa sebab", "kelelahan", "sering buang air kecil", "rasa haus berlebihan", "penglihatan kabur"},
         "diabetes tipe 2",
         "Kontrol gula darah, diet sehat",
         "Metformin, Sulfonylureas",
         "Metformin atau Sulfonylureas",
         "makanan tinggi gula",
         "sayuran hijau, biji-bijian",
         ""},
        {{"gatal-gatal", "ruam merah", "bengkak", "nyeri", "demam"},
         "alergi makanan",
         "Hindari makanan pemicu, gunakan antihistamin",
         "Loratadin, Cetirizine",
         "Loratadin atau Cetirizine",
         "makanan pemicu alergi",
         "buah-buahan, sayuran segar",
         ""},
        {{"kaki bengkak", "nyeri kaki", "kemerahan", "kulit hangat", "kelelahan"},
         "trombosis vena dalam",
         "Gunakan kompresi, minum obat pengencer darah",
         "Heparin, Warfarin",
         "Heparin atau Warfarin",
         "aktivitas berat, duduk terlalu lama",
         "makanan tinggi serat",
         ""},
        {{"nyeri dada", "sesak napas", "berkeringat dingin", "pusing", "mual"},
         "angina",
         "Istirahat, minum obat yang diresepkan",
         "Nitroglycerin, Beta-blocker",
         "Nitroglycerin atau Beta-blocker",
         "makanan tinggi lemak, garam",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam", "sakit tenggorokan", "batuk kering", "nyeri otot", "kelelahan"},
         "COVID-19",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Antivirus",
         "Paracetamol atau Antivirus",
         "makanan berminyak, minuman dingin",
         "buah-buahan, sayuran segar",
         ""},
        {{"gatal di area kemaluan", "keputihan abnormal", "nyeri saat berhubungan seksual", "kemerahan", "bengkak"},
         "infeksi vagina",
         "Gunakan obat antijamur, jaga kebersihan",
         "Mikonazol, Clotrimazole",
         "Mikonazol atau Clotrimazole",
         "pakaian ketat, bahan sintetis",
         "makanan rendah gula",
         ""},
        {{"sakit perut bagian bawah", "mual", "muntah", "demam", "kembung"},
         "usus buntu",
         "Segera ke rumah sakit, operasi jika perlu",
         "Antibiotik, operasi",
         "Antibiotik atau operasi",
         "makanan berminyak, makanan pedas",
         "makanan ringan, cairan",
         ""},
        {{"gatal di kulit kepala", "ruam merah", "kerak kering", "rambut rontok", "nyeri"},
         "dermatitis seboroik",
         "Gunakan sampo antijamur, jaga kebersihan",
         "Sampo ketoconazole, Kortikosteroid",
         "Sampo ketoconazole atau Kortikosteroid",
         "produk rambut berat",
         "makanan rendah alergen",
         ""},
        {{"nyeri dada", "batuk berdahak", "sesak napas", "demam", "kelelahan"},
         "tuberkulosis",
         "Minum obat sesuai resep, istirahat yang cukup",
         "Isoniazid, Rifampicin",
         "Isoniazid atau Rifampicin",
         "rokok, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"sulit tidur", "cepat marah", "kelelahan", "gangguan konsentrasi", "sakit kepala"},
         "gangguan tidur",
         "Menjaga rutinitas tidur, hindari kafein",
         "Melatonin, Difenhidramin",
         "Melatonin atau Difenhidramin",
         "kafein, alkohol",
         "makanan ringan sebelum tidur",
         ""},
        {{"batuk kronis", "sesak napas", "nyeri dada", "produksi dahak berlebih", "kelelahan"},
         "bronkitis kronis",
         "Hindari rokok, minum banyak cairan",
         "Antibiotik, Bronkodilator",
         "Antibiotik atau Bronkodilator",
         "rokok, polusi udara",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri perut", "kembung", "diare", "mual", "muntah"},
         "gastroenteritis",
         "Minum banyak cairan, hindari makanan berat",
         "Oralit, Antiemetik",
         "Oralit atau Antiemetik",
         "makanan berat, minuman bersoda",
         "makanan ringan, cairan",
         ""},
        {{"nyeri saat buang air kecil", "sering buang air kecil", "nyeri perut bagian bawah", "demam", "urin berbau"},
         "infeksi saluran kemih",
         "Minum banyak air, hindari iritasi",
         "Antibiotik, Analgesik",
         "Antibiotik atau Analgesik",
         "kafein, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"sakit kepala berat", "mual", "muntah", "sensitivitas terhadap cahaya", "gangguan penglihatan"},
         "migrain",
         "Istirahat di tempat gelap, minum obat yang diresepkan",
         "Triptan, NSAID",
         "Triptan atau NSAID",
         "kafein, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"sulit bernapas", "sesak napas", "nyeri dada", "batuk", "keringat berlebih"},
         "emboli paru",
         "Segera ke rumah sakit, minum obat pengencer darah",
         "Heparin, Warfarin",
         "Heparin atau Warfarin",
         "aktivitas berat, duduk terlalu lama",
         "makanan tinggi serat",
         ""},
        {{"demam tinggi", "nyeri sendi", "ruam merah", "nyeri otot", "sakit kepala"},
         "demam chikungunya",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Ibuprofen",
         "Paracetamol atau Ibuprofen",
         "makanan berminyak",
         "buah-buahan, sayuran segar",
         ""},
        {{"gatal di kulit", "ruam merah", "bengkak", "nyeri", "demam"},
         "alergi kontak",
         "Hindari kontak dengan alergen, gunakan antihistamin",
         "Loratadin, Cetirizine",
         "Loratadin atau Cetirizine",
         "alergen yang diketahui",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri dada", "sesak napas", "pusing", "mual", "kelelahan"},
         "kardiomiopati",
         "Hindari aktivitas berat, minum obat yang diresepkan",
         "Beta-blocker, ACE inhibitor",
         "Beta-blocker atau ACE inhibitor",
         "makanan tinggi garam, lemak",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam tinggi", "sakit tenggorokan", "batuk kering", "nyeri otot", "kelelahan"},
         "flu",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Antiviral",
         "Paracetamol atau Antiviral",
         "makanan berminyak, minuman dingin",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri perut bagian kanan bawah", "mual", "muntah", "demam", "kembung"},
         "apendisitis",
         "Segera ke rumah sakit, operasi jika perlu",
         "Antibiotik, operasi",
         "Antibiotik atau operasi",
         "makanan berminyak, makanan pedas",
         "makanan ringan, cairan",
         ""},
        {{"gatal di kulit kepala", "ruam merah", "kerak kering", "rambut rontok", "nyeri"},
         "psoriasis",
         "Gunakan krim kortikosteroid, jaga kebersihan",
         "Kortikosteroid topikal, Vitamin D analog",
         "Kortikosteroid atau Vitamin D analog",
         "produk rambut berat",
         "makanan rendah alergen",
         ""},
        {{"nyeri dada", "batuk berdahak", "sesak napas", "demam", "kelelahan"},
         "pneumonia",
         "Minum obat sesuai resep, istirahat yang cukup",
         "Antibiotik, Antipiretik",
         "Antibiotik atau Antipiretik",
         "rokok, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"sulit tidur", "cepat marah", "kelelahan", "gangguan konsentrasi", "sakit kepala"},
         "insomnia",
         "Menjaga rutinitas tidur, hindari kafein",
         "Melatonin, Difenhidramin",
         "Melatonin atau Difenhidramin",
         "kafein, alkohol",
         "makanan ringan sebelum tidur",
         ""},
        {{"sulit bernapas", "sesak napas", "nyeri dada", "batuk", "keringat berlebih"},
         "asma",
         "Hindari alergen, minum obat yang diresepkan",
         "Inhaler bronkodilator, Kortikosteroid",
         "Inhaler bronkodilator atau Kortikosteroid",
         "asap rokok, debu",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam tinggi", "nyeri sendi", "ruam merah", "nyeri otot", "sakit kepala"},
         "demam berdarah dengue",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Cairan elektrolit",
         "Paracetamol atau Cairan elektrolit",
         "makanan berminyak",
         "buah-buahan, sayuran segar",
         ""},
        {{"gatal di kulit", "ruam merah", "bengkak", "nyeri", "demam"},
         "urtikaria",
         "Hindari pemicu alergi, gunakan antihistamin",
         "Loratadin, Cetirizine",
         "Loratadin atau Cetirizine",
         "alergen yang diketahui",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri dada", "sesak napas", "pusing", "mual", "kelelahan"},
         "penyakit jantung koroner",
         "Hindari aktivitas berat, minum obat yang diresepkan",
         "Beta-blocker, ACE inhibitor",
         "Beta-blocker atau ACE inhibitor",
         "makanan tinggi garam, lemak",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam tinggi", "sakit tenggorokan", "batuk kering", "nyeri otot", "kelelahan"},
         "virus corona",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Antiviral",
         "Paracetamol atau Antiviral",
         "makanan berminyak, minuman dingin",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri perut bagian kanan bawah", "mual", "muntah", "demam", "kembung"},
         "radang usus buntu",
         "Segera ke rumah sakit, operasi jika perlu",
         "Antibiotik, operasi",
         "Antibiotik atau operasi",
         "makanan berminyak, makanan pedas",
         "makanan ringan, cairan",
         ""},
        {{"gatal di kulit kepala", "ruam merah", "kerak kering", "rambut rontok", "nyeri"},
         "dermatitis atopik",
         "Gunakan krim kortikosteroid, jaga kebersihan",
         "Kortikosteroid topikal, Emolien",
         "Kortikosteroid atau Emolien",
         "produk rambut berat",
         "makanan rendah alergen",
         ""},
        {{"nyeri dada", "batuk berdahak", "sesak napas", "demam", "kelelahan"},
         "infeksi paru-paru",
         "Minum obat sesuai resep, istirahat yang cukup",
         "Antibiotik, Antipiretik",
         "Antibiotik atau Antipiretik",
         "rokok, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"sulit tidur", "cepat marah", "kelelahan", "gangguan konsentrasi", "sakit kepala"},
         "gangguan tidur insomnia",
         "Menjaga rutinitas tidur, hindari kafein",
         "Melatonin, Difenhidramin",
         "Melatonin atau Difenhidramin",
         "kafein, alkohol",
         "makanan ringan sebelum tidur",
         ""},
        {{"sulit bernapas", "sesak napas", "nyeri dada", "batuk", "keringat berlebih"},
         "gangguan pernapasan",
         "Hindari alergen, minum obat yang diresepkan",
         "Inhaler bronkodilator, Kortikosteroid",
         "Inhaler bronkodilator atau Kortikosteroid",
         "asap rokok, debu",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam tinggi", "nyeri sendi", "ruam merah", "nyeri otot", "sakit kepala"},
         "infeksi virus",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Cairan elektrolit",
         "Paracetamol atau Cairan elektrolit",
         "makanan berminyak",
         "buah-buahan, sayuran segar",
         ""},
        {{"gatal di kulit", "ruam merah", "bengkak", "nyeri", "demam"},
         "reaksi alergi",
         "Hindari pemicu alergi, gunakan antihistamin",
         "Loratadin, Cetirizine",
         "Loratadin atau Cetirizine",
         "alergen yang diketahui",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri dada", "sesak napas", "pusing", "mual", "kelelahan"},
         "penyakit jantung",
         "Hindari aktivitas berat, minum obat yang diresepkan",
         "Beta-blocker, ACE inhibitor",
         "Beta-blocker atau ACE inhibitor",
         "makanan tinggi garam, lemak",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam tinggi", "sakit tenggorokan", "batuk kering", "nyeri otot", "kelelahan"},
         "infeksi pernapasan",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Antiviral",
         "Paracetamol atau Antiviral",
         "makanan berminyak, minuman dingin",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri perut bagian kanan bawah", "mual", "muntah", "demam", "kembung"},
         "radang usus",
         "Segera ke rumah sakit, operasi jika perlu",
         "Antibiotik, operasi",
         "Antibiotik atau operasi",
         "makanan berminyak, makanan pedas",
         "makanan ringan, cairan",
         ""},
        {{"gatal di kulit kepala", "ruam merah", "kerak kering", "rambut rontok", "nyeri"},
         "infeksi kulit",
         "Gunakan krim antijamur, jaga kebersihan",
         "Antijamur topikal, Kortikosteroid",
         "Antijamur atau Kortikosteroid",
         "produk rambut berat",
         "makanan rendah alergen",
         ""},
        {{"nyeri dada", "batuk berdahak", "sesak napas", "demam", "kelelahan"},
         "infeksi saluran pernapasan",
         "Minum obat sesuai resep, istirahat yang cukup",
         "Antibiotik, Antipiretik",
         "Antibiotik atau Antipiretik",
         "rokok, alkohol",
         "buah-buahan, sayuran segar",
         ""},
        {{"sulit tidur", "cepat marah", "kelelahan", "gangguan konsentrasi", "sakit kepala"},
         "masalah tidur",
         "Menjaga rutinitas tidur, hindari kafein",
         "Melatonin, Difenhidramin",
         "Melatonin atau Difenhidramin",
         "kafein, alkohol",
         "makanan ringan sebelum tidur",
         ""},
        {{"sulit bernapas", "sesak napas", "nyeri dada", "batuk", "keringat berlebih"},
         "masalah pernapasan",
         "Hindari alergen, minum obat yang diresepkan",
         "Inhaler bronkodilator, Kortikosteroid",
         "Inhaler bronkodilator atau Kortikosteroid",
         "asap rokok, debu",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam tinggi", "nyeri sendi", "ruam merah", "nyeri otot", "sakit kepala"},
         "infeksi virus",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Cairan elektrolit",
         "Paracetamol atau Cairan elektrolit",
         "makanan berminyak",
         "buah-buahan, sayuran segar",
         ""},
        {{"gatal di kulit", "ruam merah", "bengkak", "nyeri", "demam"},
         "alergi",
         "Hindari pemicu alergi, gunakan antihistamin",
         "Loratadin, Cetirizine",
         "Loratadin atau Cetirizine",
         "alergen yang diketahui",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri dada", "sesak napas", "pusing", "mual", "kelelahan"},
         "penyakit jantung",
         "Hindari aktivitas berat, minum obat yang diresepkan",
         "Beta-blocker, ACE inhibitor",
         "Beta-blocker atau ACE inhibitor",
         "makanan tinggi garam, lemak",
         "buah-buahan, sayuran segar",
         ""},
        {{"demam tinggi", "sakit tenggorokan", "batuk kering", "nyeri otot", "kelelahan"},
         "infeksi pernapasan",
         "Istirahat yang cukup, minum banyak cairan",
         "Paracetamol, Antiviral",
         "Paracetamol atau Antiviral",
         "makanan berminyak, minuman dingin",
         "buah-buahan, sayuran segar",
         ""},
        {{"nyeri perut bagian kanan bawah", "mual", "muntah", "demam", "kembung"},
         "radang usus",
         "Segera ke rumah sakit, operasi jika perlu",
         "Antibiotik, operasi",
         "Antibiotik atau operasi",
         "makanan berminyak, makanan pedas",
         "makanan ringan, cairan",
         ""},
        {{"gatal di kulit kepala", "ruam merah", "kerak kering", "rambut rontok", "nyeri"},
         "infeksi kulit",
         "Gunakan krim antijamur, jaga kebersihan",
         "Antijamur topikal, Kortikosteroid",
         "Antijamur atau Kortikosteroid",
         "produk rambut berat",
         "makanan rendah alergen",
         ""},
        {{"nyeri dada", "batuk berdahak", "sesak napas", "demam", "kelelahan"},
         "infeksi saluran pernapasan",
         "Minum obat sesuai resep, istirahat yang cukup",
         "Antibiotik, Antipiretik",
         "Antibiotik atau Antipiretik",
         "rokok, alkohol",
         "buah-buahan, sayuran segar",
         ""}};

    bool lanjutkan = true;
    while (lanjutkan)
    {
        cout << "_______________________________________________________" << endl;
        cout << "=======================================================" << endl;
        char pilihan;
        string keluhanSatu,
            keluhanDua, keluhanTiga, obatpasien;

        cout << "Masukkan keluhan pertama Anda: ";
        getline(cin, keluhanSatu);

        cout << "keluhan kedua Anda(cukup ENTER jika tidak ada keluhan kedua): ";
        getline(cin, keluhanDua);

        cout << "keluhan ketiga Anda(cukup ENTER jika tidak ada keluhan ketiga): ";
        getline(cin, keluhanTiga);

        cariPenyakit(daftarPenyakit, jumlahPenyakit, keluhanSatu, keluhanDua, keluhanTiga);

        string jawaban;
        cout << "Tanya lagi? (y/n): ";
        getline(cin, jawaban);

        if (jawaban != "y")
        {
            lanjutkan = false;
        }
    }

    cout << "Program selesai." << endl;

    return 0;
}
