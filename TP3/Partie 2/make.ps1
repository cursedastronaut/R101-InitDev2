Invoke-Expression "g++ mainIntroRecherche.cpp -o TP3-p2.exe"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./TP3-p2.exe"
}