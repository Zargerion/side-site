$services = Get-WmiObject Win32_Process | Where-Object {($_.Name -like '*chrome*')} | Select @{Name="UserName";Expression={$_.GetOwner().User}} | Sort-Object UserName 
$svc = $services | Select-Object @{N='{#UserName}'; E={$_.UserName}} -Unique 
$json = convertto-json $svc 

write-host "{"

write-host " `"data`":$json" 

write-host "}"

write-host
