/*
Ekta we application ee ip request asbe onkgula, egula block or allow kora lagbe 

1. Whether they are blacklisted or not

2. Whether too many requests from same ip came within last 5 seconds.

3. Save the current request.

4. Finally give the status of all request in the corresponding order they occurred.


C# er ekta code create kora ase oop diye, ei 4 ta function implement korte hobe, built-in function diye kora jabe na, kisu helper function bola ase, oigula use korte hobe.

Arr c# er entity gula kibhabe use korte hobe oigular kisu example deya ae
*/

// c#
using System;
using System.Collections.Generic;
using System.Linq;

public class Firewall
{
    private HashSet<string> blacklistedIPs;
    private Dictionary<string, List<DateTime>> requestLogs;
    private List<(string ip, string status)> requestHistory;
    private readonly int timeWindowSeconds = 5;
    private readonly int maxRequests = 5; // Max requests in 5 seconds

    public Firewall(HashSet<string> blacklistedIPs)
    {
        this.blacklistedIPs = blacklistedIPs;
        this.requestLogs = new Dictionary<string, List<DateTime>>();
        this.requestHistory = new List<(string ip, string status)>();
    }

    // 1. Check Blacklist
    private bool IsBlacklisted(string ip)
    {
        return blacklistedIPs.Contains(ip);
    }

    // 2. Check Rate Limit
    private bool IsRateLimited(string ip)
    {
        DateTime now = DateTime.UtcNow;

        if (!requestLogs.ContainsKey(ip))
            requestLogs[ip] = new List<DateTime>();

        // Remove old timestamps beyond the time window
        requestLogs[ip].RemoveAll(time => (now - time).TotalSeconds > timeWindowSeconds);

        // Check request count
        if (requestLogs[ip].Count >= maxRequests)
            return true;

        return false;
    }

    // 3. Save Request
    private void SaveRequest(string ip, bool allowed)
    {
        requestLogs[ip].Add(DateTime.UtcNow);
        requestHistory.Add((ip, allowed ? "Allowed" : "Blocked"));
    }

    // 4. Handle Request
    public void HandleRequest(string ip)
    {
        if (IsBlacklisted(ip))
        {
            SaveRequest(ip, false);
        }
        else if (IsRateLimited(ip))
        {
            SaveRequest(ip, false);
        }
        else
        {
            SaveRequest(ip, true);
        }
    }

    // 5. Get Request Status History
    public List<(string ip, string status)> GetRequestHistory()
    {
        return requestHistory;
    }
}

class Program
{
    static void Main()
    {
        HashSet<string> blacklistedIPs = new HashSet<string> { "192.168.1.10", "10.0.0.5" };
        Firewall firewall = new Firewall(blacklistedIPs);

        string[] requests = { "192.168.1.1", "192.168.1.10", "192.168.1.1", "10.0.0.5", "192.168.1.1", "192.168.1.1" };

        foreach (string ip in requests)
        {
            firewall.HandleRequest(ip);
        }

        var history = firewall.GetRequestHistory();
        foreach (var record in history)
        {
            Console.WriteLine($"{record.ip}: {record.status}");
        }
    }
}

// cpp
#include <bits/stdc++.h>
using namespace std;

class Firewall {
private:
    unordered_set<string> blacklistedIPs;
    unordered_map<string, vector<int>> requestLogs;
    vector<pair<string, string>> requestHistory;
    const int timeWindowSeconds = 5;
    const int maxRequests = 5;

public:
    Firewall(unordered_set<string> blacklistedIPs) {
        this->blacklistedIPs = move(blacklistedIPs);
    }

    // 1. Check if IP is blacklisted
    bool isBlacklisted(const string& ip) {
        return blacklistedIPs.count(ip);
    }

    // 2. Check if too many requests came in last 5 seconds
    bool isRateLimited(const string& ip, int currentTime) {
        if (!requestLogs.count(ip)) {
            requestLogs[ip] = vector<int>();
        }

        // Remove old timestamps beyond time window
        auto& timestamps = requestLogs[ip];
        while (!timestamps.empty() && currentTime - timestamps.front() > timeWindowSeconds) {
            timestamps.erase(timestamps.begin());
        }

        // Check request count in time window
        if (timestamps.size() >= maxRequests) {
            return true;
        }

        return false;
    }

    // 3. Save Request
    void saveRequest(const string& ip, int currentTime, bool allowed) {
        requestLogs[ip].push_back(currentTime);
        requestHistory.emplace_back(ip, allowed ? "Allowed" : "Blocked");
    }

    // 4. Handle Request
    void handleRequest(const string& ip, int currentTime) {
        if (isBlacklisted(ip)) {
            saveRequest(ip, currentTime, false);
        } else if (isRateLimited(ip, currentTime)) {
            saveRequest(ip, currentTime, false);
        } else {
            saveRequest(ip, currentTime, true);
        }
    }

    // 5. Get Request Status History
    void getRequestHistory() {
        for (const auto& record : requestHistory) {
            cout << record.first << ": " << record.second << endl;
        }
    }
};

int main() {
    unordered_set<string> blacklistedIPs = {"192.168.1.10", "10.0.0.5"};
    Firewall firewall(blacklistedIPs);

    vector<pair<string, int>> requests = {
        {"192.168.1.1", 1}, {"192.168.1.10", 2}, {"192.168.1.1", 3},
        {"10.0.0.5", 4}, {"192.168.1.1", 6}, {"192.168.1.1", 7},
        {"192.168.1.1", 8}, {"192.168.1.1", 9}, {"192.168.1.1", 10},
        {"192.168.1.1", 11} // This should be blocked
    };

    for (const auto& req : requests) {
        firewall.handleRequest(req.first, req.second);
    }

    firewall.getRequestHistory();

    return 0;
}

// java
import java.util.*;

class Firewall {
    private Set<String> blacklistedIPs;
    private Map<String, List<Integer>> requestLogs;
    private List<Pair<String, String>> requestHistory;
    private final int timeWindowSeconds = 5;
    private final int maxRequests = 5;

    public Firewall(Set<String> blacklistedIPs) {
        this.blacklistedIPs = blacklistedIPs;
        this.requestLogs = new HashMap<>();
        this.requestHistory = new ArrayList<>();
    }

    // 1. Check if IP is blacklisted
    private boolean isBlacklisted(String ip) {
        return blacklistedIPs.contains(ip);
    }

    // 2. Check if too many requests came in last 5 seconds
    private boolean isRateLimited(String ip, int currentTime) {
        requestLogs.putIfAbsent(ip, new ArrayList<>());
        List<Integer> timestamps = requestLogs.get(ip);

        // Remove old timestamps beyond time window
        timestamps.removeIf(time -> (currentTime - time) > timeWindowSeconds);

        // Check request count in time window
        return timestamps.size() >= maxRequests;
    }

    // 3. Save Request
    private void saveRequest(String ip, int currentTime, boolean allowed) {
        requestLogs.get(ip).add(currentTime);
        requestHistory.add(new Pair<>(ip, allowed ? "Allowed" : "Blocked"));
    }

    // 4. Handle Request
    public void handleRequest(String ip, int currentTime) {
        if (isBlacklisted(ip)) {
            saveRequest(ip, currentTime, false);
        } else if (isRateLimited(ip, currentTime)) {
            saveRequest(ip, currentTime, false);
        } else {
            saveRequest(ip, currentTime, true);
        }
    }

    // 5. Get Request Status History
    public void getRequestHistory() {
        for (Pair<String, String> record : requestHistory) {
            System.out.println(record.getFirst() + ": " + record.getSecond());
        }
    }

    // Helper Pair Class (Since Java doesn't have built-in Pair)
    static class Pair<T, U> {
        private final T first;
        private final U second;

        public Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }

        public T getFirst() {
            return first;
        }

        public U getSecond() {
            return second;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Set<String> blacklistedIPs = new HashSet<>(Arrays.asList("192.168.1.10", "10.0.0.5"));
        Firewall firewall = new Firewall(blacklistedIPs);

        List<Pair<String, Integer>> requests = Arrays.asList(
            new Firewall.Pair<>("192.168.1.1", 1),
            new Firewall.Pair<>("192.168.1.10", 2),
            new Firewall.Pair<>("192.168.1.1", 3),
            new Firewall.Pair<>("10.0.0.5", 4),
            new Firewall.Pair<>("192.168.1.1", 6),
            new Firewall.Pair<>("192.168.1.1", 7),
            new Firewall.Pair<>("192.168.1.1", 8),
            new Firewall.Pair<>("192.168.1.1", 9),
            new Firewall.Pair<>("192.168.1.1", 10),
            new Firewall.Pair<>("192.168.1.1", 11) // This should be blocked
        );

        for (Pair<String, Integer> req : requests) {
            firewall.handleRequest(req.getFirst(), req.getSecond());
        }

        firewall.getRequestHistory();
    }
}
