# https://leetcode.com/problems/top-k-frequent-words/
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        out = []
        count_dict = {}
        for word in words:
            if word not in count_dict:
                count_dict[word] = 1
            else:
                count_dict[word] += 1
        count_dict = dict(sorted(count_dict.items(), key=lambda item: (-item[1], item[0])))
        i = 0
        for key in count_dict.keys():
            if i < k:
                out.append(key)
                i += 1
            else:
                break
        return out