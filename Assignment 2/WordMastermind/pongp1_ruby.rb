#Reading the words from the wordlist file an storing it in an array
array_codes = []
File.open("mastermindWordList.txt", "r") do |aFile|
while(line = aFile.gets)
    if line.chars.uniq.count { |char| line.downcase.count(char) > 1 } == 0 #if the word does not contain the same letters put the word in the array
        array_codes.push line #putting the word in the array
    end
end
aFile.close #closing the file reading
end

#setting up the variables
continue = "y"

#loop to continue playing game
while continue == "y" #loop will continue until the variable continue is no longer "y"
	
	#initializing components
	guess_count = 1
	code = array_codes.shuffle.first #shuffling the code array and grabbing the first item in the array 

	#game messages, this will print the message to the console
	puts "Guess the mystery five letters word, beware you only ten tries!"
	puts "Exact = You got the character exactly correct"
	puts "Near = You got the character correct but not in the correct position"
	puts "Miss = You got the character wrong\n\n"

	#looping through for a guess, this will continue to loop till guess is the same as the code or guess_count exceeds 10
	loop do
		x = 0
		guess = ''
		
		#forcing player to enter a word that is five characters 
		loop do 
			puts "Guess number " + guess_count.to_s #'.to_s' is to convert the variable guess_count which is an int to a string so we can display the guess number that the player is on
			puts "Enter your guess: "
			guess = gets
			if guess.length < 5 #if the length of the variable guess is less that five characters, display an error message
				puts "\nWord entered is too short, must be five characters\n" #error message that the player will see
			end
			break if guess.length >= 5 #loop will break when variable guess is longer than five characters
		end
		
		loop do #looping through all the letters in guess 
			#three different outcomes
			if code[x] == guess[x] #if the letter from guess is exactly the same in the same position print "Exact"
				print "Exact "
			elsif code.include? guess[x] #if the letter from guess is in the the variable code but not in the same position print "Near"
				print "Near "
			else #Anything else print "Miss" meaning that the letter is not in the variable code
				print "Miss "
			end
			x += 1 #index controller that will loop through all the characters of both variable code and guess
			break if x > 4 #breaking out of the loop after five loops since all the codes are five characters
		end
		
		puts "\n\n"
		guess_count += 1 #incrementing the guess counter by one
		
		break if code === guess #breaking out of the loop if variable guess is the same as variable code meaning you guess the word correctly
		break if guess_count > 10 #breaking out of the loop when guess_count exceeds 10
	end
	
	#showing win/loss message
	if guess_count > 10 #if the guess loop was exited because the variable guess_count exceeds 10 then the player loss
		puts "Sorry you lost!!"
		puts "The code was " + code
	else #if the player break the guess loop by matching their guess with the code then the player won
		puts "You won!!"
	end
	
	#asking whether the player wants to continue
	puts "\nPress 'y' to play again: "
	continue = gets.chomp #using chomp to get rid of the line break '\n'
	break if continue != 'y' #game will stop if the player enters anything else but 'y', this will break the game loop
end