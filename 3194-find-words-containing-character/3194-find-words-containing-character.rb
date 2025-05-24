# @param {String[]} words
# @param {Character} x
# @return {Integer[]}
def find_words_containing(words, x)
    indexArray = []
    words.each_with_index { |word,idx|
        if(word.include?(x))
            indexArray.append(idx)
        end
    }
    return indexArray
end