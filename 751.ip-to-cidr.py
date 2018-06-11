class Solution(object):
    def ipToCIDR(self, ip, n):
        """
        :type ip: str
        :type n: int
        :rtype: List[str]
        """
        ip_int = self.ip2int(ip)
        ans = []
        x = 0
        while x < n:
            zeros = self.calc(ip_int + x)
            while x + (1<<zeros) > n:
                zeros -= 1
            ans.append(str(self.int2ip(ip_int + x)) + "/" + str(32 - zeros))
            x += 1 << zeros
        return ans

    def calc(self, ip) :
        cnt = 0
        while ip:
            if ip & 1 : break
            cnt += 1
            ip >>= 1
        return cnt

    def int2ip(self, d):
        ans = []
        for x in xrange(4):
            ans.append((d >> x * 8) & 255)
        return '.'.join(map(str, ans[::-1]))
    def ip2int(self, ip):
        ans = 0
        for idx, part in enumerate(ip.split('.')[::-1]):
            ans += int(part) << idx * 8
        return ans


