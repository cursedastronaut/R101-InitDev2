Invoke-Expression "g++ main.cpp permis.cpp -o permis.exe"
if ($args -contains "-run") {
    Invoke-Expression "./permis.exe"
}