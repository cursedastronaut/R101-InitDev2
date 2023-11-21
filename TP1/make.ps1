Invoke-Expression "g++ main.cpp permis.cpp -o permis.exe"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./permis.exe"
}