# LoL-Team-Structure-Address
DLL that returns the last address in memory in LeagueClient.exe where the team lobby JSON structure is.

Example of the JSON structure.
```json
[{"assignedPosition":"","cellId":0,"championId":0,"championPickIntent":0,"displayName":"YourSummonerName","playerType":"PLAYER","selectedSkinId":0,"spell1Id":6,"spell2Id":7,"summonerId":12345678,"team":1,"wardSkinId":0},  
{"assignedPosition":"","cellId":1,"championId":36,"championPickIntent":0,"displayName":"DrMundo bot","playerType":"BOT","selectedSkinId":36000,"spell1Id":18446744073709551615,"spell2Id":18446744073709551615,"summonerId":0,"team":1,"wardSkinId":-1},
{"assignedPosition":"","cellId":2,"championId":26,"championPickIntent":0,"displayName":"Zilean bot","playerType":"BOT","selectedSkinId":26000,"spell1Id":18446744073709551615,"spell2Id":18446744073709551615,"summonerId":0,"team":1,"wardSkinId":-1},
{"assignedPosition":"","cellId":3,"championId":20,"championPickIntent":0,"displayName":"Nunu bot","playerType":"BOT","selectedSkinId":20000,"spell1Id":18446744073709551615,"spell2Id":18446744073709551615,"summonerId":0,"team":1,"wardSkinId":-1},
{"assignedPosition":"","cellId":4,"championId":16,"championPickIntent":0,"displayName":"Soraka bot","playerType":"BOT","selectedSkinId":16000,"spell1Id":18446744073709551615,"spell2Id":18446744073709551615,"summonerId":0,"team":1,"wardSkinId":-1}]
```
  
C# class to serialize the JSON data. 
```csharp
public class LobbyPlayer  
{  
    public string assignedPosition { get; set; }
    public int cellId { get; set; }
    public int championId { get; set; }
    public int championPickIntent { get; set; }
    public string displayName { get; set; }
    public string playerType { get; set; }
    public int selectedSkinId { get; set; }
    public double spell1Id { get; set; }
    public double spell2Id { get; set; }
    public int summonerId { get; set; }
    public int team { get; set; }
    public int wardSkinId { get; set; }
}
```
