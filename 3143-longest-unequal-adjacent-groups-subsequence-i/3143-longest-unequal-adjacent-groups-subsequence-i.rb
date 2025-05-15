# @param {String[]} words
# @param {Integer[]} groups
# @return {String[]}
def get_longest_subsequence(words, groups)
    ans = []
    last = -1
    words.each_with_index do |word, i|
      if groups[i] != last
        ans << word
        last = groups[i]
      end
    end
    ans
  end