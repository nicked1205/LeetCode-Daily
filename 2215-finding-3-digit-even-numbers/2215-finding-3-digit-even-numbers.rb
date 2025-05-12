# @param {Integer[]} digits
# @return {Integer[]}

def find_even_numbers(digits)
    res = []
    freq = Hash.new(0)
    
    digits.each { |digit| freq[digit] += 1 }

    puts freq

    (0..9).each do |last_digit|
        next unless last_digit.even? && freq[last_digit] > 0

        (0..9).each do |second_digit|
            next if freq[second_digit] == 0
            next if second_digit == last_digit && freq[second_digit] < 2

            (0..9).each do |first_digit|
                next if first_digit == 0 || freq[first_digit] == 0
                next if first_digit == second_digit && freq[first_digit] < 2
                next if first_digit == last_digit && freq[first_digit] < 2
                next if first_digit == last_digit && first_digit == second_digit && freq[first_digit] < 3
                
                res << (first_digit * 100 + second_digit * 10 + last_digit)
            end
        end
    end

    res.uniq.sort
end