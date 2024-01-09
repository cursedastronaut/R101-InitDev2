Invoke-Expression "g++ .\main.cpp .\chocolat.cpp .\boitechoco.cpp .\magasin.cpp -o TP6.exe --std=c++17"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./TP6.exe"
}