import sqlite3

con = sqlite3.Connection('../data/coworking.db')
cur = con.cursor()

cur.execute('CREATE TABLE Clients(id INT PRIMARY KEY, full_name VARCHAR, phone TEXT, email TEXT, date_of_registration DATE, status VARCHAR, orders_id INT, FOREIGN KEY(orders_id) REFERENCES Orders(id))')

cur.execute('CREATE TABLE Employees(id INT PRIMARY KEY, full_name VARCHAR, phone TEXT, email TEXT, job_title VARCHAR, hire_date DATE)')

cur.execute('CREATE TABLE Equipments(id INT PRIMARY KEY, description VARCHAR, equipments_tyoes_id INT, FOREIGN KEY(equipments_tyoes_id) REFERENCES Equipments_tyoes(id))')

cur.execute('CREATE TABLE Equipments_types(id INT PRIMARY KEY, name VARCHAR)')

cur.execute('CREATE TABLE Orders(id INT PRIMARY KEY, price DECIMAL(10,2), clients_id INT, FOREIGN KEY(clients_id) REFERENCES Clients(id))')

cur.execute('CREATE TABLE Rent(id INT PRIMARY KEY, employees_id INT, booking_date DATE, start_date DATE, end_date DATE, status VARCHAR, workplace_id INT, orders_id INT, FOREIGN KEY (employees_id) REFERENCES Employees(id), FOREIGN KEY (workplace_id) REFERENCES Workplace(id), FOREIGN KEY (orders_id) REFERENCES Orders(id))')

cur.execute('CREATE TABLE Rooms(id INT PRIMARY KEY, location TEXT, description TEXT, square DECIMAL(10, 2), rooms_type_id INT, FOREIGN KEY (rooms_type_id) REFERENCES Rooms_type(id))')

cur.execute('CREATE TABLE Rooms_type(id INT PRIMARY KEY, name VARCHAR)')

cur.execute('CREATE TABLE Type_of_workplace(id INT PRIMARY KEY, name VARCHAR)')

cur.execute('CREATE TABLE Workplace(id INT PRIMARY KEY, number INT, price DECIMAL(10, 2), rooms_id INT, types_of_workplace_id INT, FOREIGN KEY (rooms_id) REFERENCES Rooms(id), FOREIGN KEY (types_of_workplace_id) REFERENCES Type_of_workplace(id))')

cur.execute('CREATE TABLE Reviews(id INT PRIMARY KEY, review TEXT, clients_id INT, FOREIGN KEY (clients_id) REFERENCES Clients(id))')

con.commit()
con.close()
# import requests
# import sqlite3

# # Подключение к SQLite
# con = sqlite3.Connection('../data/coworking.db')
# cur = con.cursor()

# # URL и заголовки для доступа к Supabase
# url = "https://mmkkdvaufklhjqotgjza.supabase.co/rest/v1/Clients"
# headers = {
#     "apikey": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Im1ta2tkdmF1ZmtsaGpxb3RnanphIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MzI1OTYxNTMsImV4cCI6MjA0ODE3MjE1M30.UeKrkn0w4cvYO3ULRA61UOpRi4UyfiJm5b1aDyTgTOg",
#     "Authorization": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6Im1ta2tkdmF1ZmtsaGpxb3RnanphIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MzI1OTYxNTMsImV4cCI6MjA0ODE3MjE1M30.UeKrkn0w4cvYO3ULRA61UOpRi4UyfiJm5b1aDyTgTOg",
#     "Content-Type": "application/json"
# }

# # Получение данных из Supabase
# response = requests.get(url, headers=headers)

# if response.status_code == 200:
#     clients_data = response.json()
#     for client in clients_data:
#         cur.execute('INSERT INTO Clients (id, full_name, phone, email, date_of_registration, status, orders_id) VALUES (?, ?, ?, ?, ?, ?, ?)',
#                     (client['id'], client['full_name'], client['phone'], client['email'], client['date_of_registration'], client['status'], client['orders_id']))
# else:
#     print(f"Ошибка при получении данных: {response.status_code}")

# con.commit()
# con.close()
