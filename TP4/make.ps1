Invoke-Expression "g++ .\main.cpp .\rat.cpp -o TP4.exe"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./TP4.exe"
}