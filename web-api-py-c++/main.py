from telegram import Update
from telegram.ext import ApplicationBuilder, CommandHandler,ContextTypes
import os
from dotenv import load_dotenv

load_dotenv()

async def start(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    await update.message.reply_text(f'Hello {update.effective_user.first_name}!')
    await context.bot.send_message(
        chat_id=update.effective_chat.id,
        text="I'm a bot, please talk to me!"
    )

application = ApplicationBuilder().token('6173190003:AAE7rhy7RLG53QTquwkZaNDG0ODY9MkGaYI').build()

application.add_handler(CommandHandler('start', start))

application.run_polling()