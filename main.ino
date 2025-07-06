import openai
import os

# Use your own OpenAI key here
openai.api_key = os.getenv("OPENAI_API_KEY") or "YOUR_OPENAI_API_KEY"

# Initial system instruction (bot's personality)
conversation = [
    {"role": "system", "content": "You are a helpful and friendly AI assistant."}
]

def ask_gpt(user_input):
    # Append the new user message
    conversation.append({"role": "user", "content": user_input})

    try:
        # Send request to OpenAI
        response = openai.ChatCompletion.create(
            model="gpt-3.5-turbo",  # Use "gpt-4" if you have access
            messages=conversation
        )
        reply = response['choices'][0]['message']['content'].strip()
        # Append the assistant's reply to the conversation
        conversation.append({"role": "assistant", "content": reply})
        return reply

    except Exception as e:
        return f"⚠️ Error: {str(e)}"

def main():
    print("🤖 AI Chatbot (type 'exit' to quit)")
    while True:
        user_input = input("You: ")
        if user_input.lower() == "exit":
            print("Goodbye!")
            break
        reply = ask_gpt(user_input)
        print("AI:", reply)

if __name__ == "__main__":
    main()
