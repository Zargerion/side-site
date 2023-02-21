Param([string] $user)
$user= $user.Replace(' ','')
$services = Get-WmiObject Win32_Process | Where-Object {($_.Name -like '*chrome*')} | Select CommandLine, Name, @{Name="UserName";Expression={$_.GetOwner().User}}, @{Name="MemUsage";Expression={[math]::round($_.ws / 1mb)}} | Sort-Object UserName, Name
$userservice = $services | Where-Object {($_.UserName -like $user)}
$svc = $userservice | Select-Object @{N='UserName'; E={$_.UserName}}, @{N='MemUsage'; E={$_.MemUsage}}
$result = $svc.MemUsage 
Write-Host ($result -split ' '  | measure-object -sum).sum