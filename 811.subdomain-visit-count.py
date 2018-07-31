class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        ms = dict()
        for item in cpdomains:
            cnt, domain = item.split(' ')
            domain = domain.split('.')
            for i in range(0, len(domain)):
                s = '.'.join(domain[i:])
                ms[s] = ms.get(s, 0) + int(cnt)

        ans = list()
        for k, v in ms.items():
            ans.append(str(v) + ' ' + k)

        return ans



