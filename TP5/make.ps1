Invoke-Expression "g++ .\main.cpp .\outils.cpp vecteurTrie.cpp -o TP5.exe"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./TP5.exe"
}