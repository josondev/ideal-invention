import os
import nest_asyncio  # Ensure this is applied before asynchronous operations
from lyzr import ChatBot, SearchAgent  # Assuming these are correct imports
#%env OPENAI_API_KEY=key(must to keep the key safe)
nest_asyncio.apply()# Apply nest_asyncio once at the start

class MAIN:
    def __init__(self, ans):
        self.ans = ans
        self.key = os.getenv("OPENAI_API_KEY")
        if not self.key:
            raise ValueError("API key not found. Please set the OPENAI_API_KEY environment variable.")
            
    def main(self):
        if self.ans == 'voice':
            ans = input('Text-to-speech or Transcribe or Text-to-notes: ')
            Voice(ans,self.key)
        elif self.ans == 'summariser':
            Summariser(self.key)
        elif self.ans == 'generator':
            Generator(self.key)
        else:
            os.environ['OPENAI_API_KEY'] = self.key
            if self.ans == 'chat':
                ans = input('word document or pdf or youtube video or website or webpage or text file: ')
                Chat(ans)
            elif self.ans == 'search':
                ans = input('word document or pdf or youtube video or website or webpage or text file: ')
                Search(ans)
            else:
                print("Enter a valid operation:")

if __name__ == '__main__':
    while True:
        try:
            ans = input('voice or search or chat or generator or summariser: ')
            obj = MAIN(ans)
            obj.main()
        except Exception as e:
            print("The following exception has occurred:", e)
            continue_program = input("Do you want to continue? (yes or no): ")
            if continue_program.lower() == "no":
                print("Exiting program.")
                break
