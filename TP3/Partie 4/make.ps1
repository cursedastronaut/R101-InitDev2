Invoke-Expression "g++ main.cpp etudiant.cpp promotion.cpp -o TP3-p4.exe"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./TP3-p4.exe"
}