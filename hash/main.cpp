#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <iostream>
using namespace CryptoPP;
using namespace std;

int main() {
    string TXT, PT, result, result1;
    FileSource("/home/stud/CryptoProg/hash/test1.txt", true, new StringSink(PT));
    PT.resize(PT.size() - 1);
    cout << "Text from TXT file: " << PT << endl;
    HexEncoder encoder(new StringSink(result));
    Weak::MD5 hash;
    hash.Update((const byte*)&PT[0], PT.size());
    TXT.resize(hash.DigestSize());
    hash.Final((byte*)&TXT[0]);
    cout << "HASH: ";
    StringSource(TXT, true, new Redirector(encoder));
    cout << result << "\n\n";
    
    //Повтор текста из файла для проверки работоспособности кода выше:
    HexEncoder encoder1(new StringSink(result1));
    string TXT1, PT1 = "Однажды ПГУ покрасят в зелёный";
    cout << "Text from program: " << PT1 << endl;
    hash.Update((const byte*)&PT1[0], PT1.size());
    TXT1.resize(hash.DigestSize());
    hash.Final((byte*)&TXT1[0]);
    cout << "HASH: ";
    StringSource(TXT1, true, new Redirector(encoder1));
    cout << result1 << endl;
    if (result == result1)
        cout << "Успешный тест!\n\n";
}
