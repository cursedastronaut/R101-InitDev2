Invoke-Expression "g++ .\appartement.cpp .\main.cpp .\piece.cpp -o TP3-p3.exe"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./TP3-p3.exe"
}