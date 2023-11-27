Invoke-Expression "g++ main.cpp appartement.cpp -o appartement.exe"
if ($args -contains "-run") {
    if ($LASTEXITCODE -ne 0) { Exit }
    Invoke-Expression "./appartement.exe"
}