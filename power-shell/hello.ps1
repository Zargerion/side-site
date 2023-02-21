Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted
Write-Host "Power is here!"
$jsFile = [System.Text.Encoding]::UTF8.GetString([System.Text.Encoding]::GetEncoding("Windows-1251").GetBytes("'C:\Users\щдуп\AppData\Roaming\npm\node_modules\@vue\cli\bin\vue.js'"))
$command = "node $jsFile"
Invoke-Expression $command