-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Begin running queries
sqlite3 fiftyville.db
-- Check the CREATE TABLE commands used to view the various tables and columns
.schema

-- Check crime scene report from July 28, 2021, for Humphrey Street.
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2021 AND street LIKE "Humphrey%";
-- Crime took place at 10:15 a.m. There were 3 witnesses who were interviewed on the same day.
-- The 3 witnesses all mention the bakery in their statements.

-- Get witness names and statements
SELECT name, transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2021 AND transcript LIKE "%bakery%";
-- Thief made a call around the time of the robbery, call lasted < 1 minute.
-- Thief asked accomplice to book flight tickets, earliest flight out of Fiftyville on July 29, 2021.
-- Thief got into a car within 10 minutes of the robbery, 10:15 a.m. to 10:25 a.m.
-- Thief withdrew money at an ATM on Leggett Street sometime before 10:15 a.m.

-- Get ATM transactions from Leggett Street on July 28, 2021.
SELECT account_number, amount FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2021 AND transaction_type LIKE "withdraw%" AND atm_location LIKE "leggett%";

-- Get car license plates from the bakery between 10:15 and 10:25 a.m. on July 28, 2021.
SELECT license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021 AND activity = "exit"
AND hour = 10 AND minute > 14 AND minute < 26;

-- Get caller, receiver for July 28, 2021, where duration < 60 seconds.
SELECT caller, receiver FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60;

-- Get Fiftyville airport ID.
SELECT id FROM airports
WHERE city = "Fiftyville";
-- Fiftyville airport ID is 8.

-- Get destination ID and flight ID of first flight out of Fiftyville on July 29, 2021.
SELECT destination_airport_id, id FROM flights
WHERE day = 29 AND month = 7 AND year = 2021
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour LIMIT 1;
-- Destination ID is 4. Flight ID is 36.

-- Get destination city of above flight.
SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights
WHERE day = 29 AND month = 7 AND year = 2021
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour LIMIT 1);
-- Destination city is New York City.

-- Get names of people who:
-- 1. Made a phone call of duration < 1 minute.
-- 2. Were seen exiting the bakery parking lot within 10 minutes of the crime.
-- 3. Were seen withdrawing money from the Leggett Street ATM.
-- All the above actions took place on July 28, 2021.
SELECT name FROM people
WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60)
AND license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021 AND activity = "exit"
AND hour = 10 AND minute > 14 AND minute < 26)
AND id IN
(SELECT person_id FROM bank_accounts
WHERE account_number IN
(SELECT account_number FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2021 AND transaction_type LIKE "withdraw%" AND atm_location LIKE "leggett%"));
-- We get back the names of two suspects: Diana and Bruce.

-- Get passport numbers of Diana and Bruce.
SELECT passport_number, name FROM people
WHERE name = 'Diana' OR name = 'Bruce';

-- Find the thief by checking the passport numbers of the suspects
-- and the passport numbers of the passengers of the first flight out of Fiftyville on July 29, 2021.
SELECT name FROM people
WHERE passport_number IN
(SELECT passport_number FROM passengers
JOIN flights on flights.id = passengers.flight_id
WHERE flight_id IN
(SELECT id FROM flights
WHERE day = 29 AND month = 7 AND year = 2021
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour LIMIT 1))
AND passport_number IN
(SELECT passport_number FROM people
WHERE name = 'Diana' OR name = 'Bruce');
-- Thief is Bruce.

-- Find Bruce's accomplice using the available call records.
SELECT name FROM people
WHERE phone_number =
(SELECT receiver FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021 AND duration < 60
AND caller = (SELECT phone_number FROM people
WHERE name = 'Bruce'));
-- Accomplice is Robin.