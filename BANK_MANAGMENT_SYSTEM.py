customer_records = {}
current_account = None
next_account_number = 10100

def display_menu():
    print("\n--- Bank Management System ---")
    print("1. Create Account")
    print("2. Deposit")
    print("3. Withdraw")
    print("4. Transfer Funds")
    print("5. List Account Holders")
    print("6. Close Account")
    print("7. Modify Name")
    print("8. Check Balance")
    print("9. Exit")
    try:
        choice = int(input("Enter your choice: "))
        return choice
    except ValueError:
        print("Invalid choice. Please enter a number.")
        return None

def create_account():
    global next_account_number, current_account
    name = input("Enter your name: ")
    next_account_number += 1
    account_number = next_account_number
    try:
        balance = float(input("Enter initial deposit: "))
    except ValueError:
        print("Invalid input for balance. Please enter a valid number.")
        return
    customer_records[account_number] = {"name": name, "balance": balance}
    print("Account created successfully. Your account number is:", account_number)
    current_account = account_number

def deposit():
    global current_account
    if not current_account:
        print("Please login to your account.")
        return
    account_number = current_account
    try:
        amount = float(input("Enter amount to deposit: "))
    except ValueError:
        print("Invalid input for amount. Please enter a valid number.")
        return
    customer_records[account_number]["balance"] += amount
    print(f"Deposited {amount:.2f}. New balance: {customer_records[account_number]['balance']:.2f}")

def withdraw():
    global current_account
    if not current_account:
        print("Please login to your account.")
        return
    account_number = current_account
    try:
        amount = float(input("Enter amount to withdraw: "))
    except ValueError:
        print("Invalid input for amount. Please enter a valid number.")
        return
    available_balance = customer_records[account_number]["balance"]
    if amount > available_balance:
        print("Insufficient balance.")
        return
    customer_records[account_number]["balance"] -= amount
    print(f"Withdrawn {amount:.2f}. New balance: {customer_records[account_number]['balance']:.2f}")

def transfer_funds():
    print("This feature requires verification and is unavailable at this time.")

def list_account_holders():
    print("Account Holder List".center(70, '-'))
    for account_number, data in customer_records.items():
        print(account_number, data['name'], data['balance'])

def close_account():
    global current_account
    if not current_account:
        print("Please login to your account.")
        return
    account_number = current_account
    del customer_records[account_number]
    print("Your account is closed.")
    current_account = None

def modify_name():
    global current_account
    if not current_account:
        print("Please login to your account.")
        return
    account_number = current_account
    new_name = input("Enter new name: ")
    customer_records[account_number]['name'] = new_name
    print(f"Name changed to {new_name}")

def check_balance():
    global current_account
    if not current_account:
        print("Please login to your account.")
        return
    account_number = current_account
    print(f"Your balance is: {customer_records[account_number]['balance']:.2f}")

while True:
    choice = display_menu()

    if choice == 1:
        create_account()
    elif choice == 2:
        deposit()
    elif choice == 3:
        withdraw()
    elif choice == 4:
        transfer_funds()
    elif choice == 5:
        list_account_holders()
    elif choice == 6:
        close_account()
    elif choice == 7:
        modify_name()
    elif choice == 8:
        check_balance()
    elif choice == 9:
        print("Exiting Bank Management System.")
        break
    else:
        print("Invalid choice. Please try again.")
