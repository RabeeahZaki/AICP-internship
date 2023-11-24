num_journeys = 4
num_coaches = 6
seats_per_coach = 80
ticket_price = 25
extra_coaches_last_train = 2

cash_up = [0] * num_journeys
cash_down = [0] * num_journeys
available_seats_up = [seats_per_coach * num_coaches] * num_journeys
available_seats_down = [seats_per_coach * num_coaches] * num_journeys

def display_table_header(journey_type):
    print(f"\n{journey_type} Journeys")
    print("{:<15}{:<20}{:<20}{:<20}".format("Journey", "Departure Time", "Available Seats", "Total cash"))
    print("-" * 75)

def display_journey_details(journey_type, journey_index, departure_time, available_seats, total_cash):
    print("{:<15}{:<20}{:<20}{:<20}".format(f"{journey_type} {journey_index + 1}", departure_time,available_seats if available_seats > 0 else "Closed", f"${total_cash}"))

def display_start_of_day():
    display_table_header("Up")
    for i in range(num_journeys):
        display_journey_details("Up", i, f"{9 + i * 2}:00", available_seats_up[i], cash_up[i])

    display_table_header("Down")
    for i in range(num_journeys):
        display_journey_details("Down", i, f"{10 + i * 2}:00", available_seats_down[i], cash_down[i])

def purchase_tickets():
    journey_type = int(input("\nEnter the type of journey (1 for Up, 2 for Down): "))

    if journey_type not in [1, 2]:
        print("Invalid journey type. Please enter 1 for Up or 2 for Down.")
        return

    journey_index = int(input("Enter the journey index (1 to 4): "))

    if journey_index not in range(1, num_journeys + 1):
        print("Invalid journey index. Please enter a number between 1 and 4.")
        return

    num_tickets = int(input("Enter the number of tickets to purchase: "))

    if num_tickets not in range(1, available_seats(journey_type, journey_index) + 1):
        print(f"Invalid number of tickets. Please enter a number between 1 and {available_seats(journey_type, journey_index)}.")
        return

    cash = cash_up if journey_type == 1 else cash_down
    available_seats_list = available_seats_up if journey_type == 1 else available_seats_down
    # Update available seats
    if available_seats_list[journey_index - 1] > num_tickets:   
        available_seats_list[journey_index - 1] -= num_tickets

    cash[journey_index - 1] += calculate_ticket_price(num_tickets)

    print("Tickets purchased successfully!")
    
#     if(available_seats_list[journey_index - 1]==0):
#         print(f"{journey_type} -{journey_index} is closed")
#         return purchase_tickets()
#     else:
#         print("-------------------------------END OF THE DAY-------------------------")
#         Total_Cash=sum(cash_up)+sum(cash_down)
#         Total_passengers=num_tickets
#         print("Total passengers for the day=",Total_passengers)
#         print("Total cash=",Total_Cash)
    # Update the display after the purchase
    display_start_of_day()


#     max_passengers_index = find_max_passengers_index()
#     print("\nJourney with the most passengers today: ", end="")
#     if max_passengers_index != -1:
#         print(f"Journey {max_passengers_index + 1} (Up: {passengers_up[max_passengers_index]}, Down: {passengers_down[max_passengers_index]})")
#     else:
#         print("No data available.")

def available_seats(journey_type, journey_index):
    return available_seats_up[journey_index - 1] if journey_type == 1 else available_seats_down[journey_index - 1]

def calculate_ticket_price(num_tickets):
    free_passenger_interval = num_tickets // 10
    full_price_tickets=(num_tickets-free_passenger_interval)* ticket_price
    return full_price_tickets 

# def find_max_passengers_index():
#     max_passengers = -1
#     max_index = -1
#     for i in range(num_journeys):
#         total_passengers = passengers_up[i] + passengers_down[i]
#         if total_passengers > max_passengers:
#             max_passengers = total_passengers
#             max_index = i
#     return max_index
while(True):
# Start of the day
    display_start_of_day()

# Purchasing tickets
    purchase_tickets()
