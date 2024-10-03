-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Theft took place on July 28 on Humphrey Street, identify the thief, where they escaped to and who the accomplice is.
-- 1st query is to start with the crime scene reports:
SELECT * FROM crime_scene_reports
   ...> WHERE month = 7 AND day = 28 AND street = "Humphrey Street";
-- Crime_scene_report ID 295 is the correct one: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
SELECT * FROM interviews WHERE year = 2023 AND month = 7 and day = 28 AND transcript LIKE "%bakery%";
--| 161 | Ruth    | 2023 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | 2023 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | 2023 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
-- Thief was in Bakery Parking lot from 10:05am-10:25am, withdrew money from the ATM on Leggett Street, made a phone call at around 10:15am, and left on the earliest flight from Fiftyville on the 29th of July 2023, the accomplice would have purchased the tickets on the 28th around 10:15am.
-- Bakery Parking lot - every who left
SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 and activity = "exit";
/*
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
+-----+------+-------+-----+------+--------+----------+---------------+
*/
-- Identify vehicle owners
SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 and activity = "exit";
/*
Suspect List:
+---------+
|  name   |
+---------+
| Vanessa |
| Bruce   |
| Barry   |
| Luca    |
| Sofia   |
| Iman    |
| Diana   |
| Kelsey  |
+---------+
*/
-- Leggett Street ATM
SELECT * FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

/*
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
*/
-- Who are the people who withdrew:
SELECT name FROM people
   ...> JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
   ...> JOIN bank_accounts ON bank_accounts.person_id = people.id
   ...> WHERE atm_transactions.year = 2023 AND atm_transactions.month = 7 and atm_transactions.day = 28 and atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw";
/*
+---------+
|  name   |  Compare to other list:
+---------+
| Bruce   |
| Diana   |
| Iman    |
| Luca    |
+---------+
*/
-- Phone Calls on that day that lasted less than one minute:
SELECT * FROM phone_calls
   ...> WHERE year = 2023 AND month = 7 AND day = 28 AND duration <= 60;
/*
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2023 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2023 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
| 234 | (609) 555-5876 | (389) 555-5198 | 2023 | 7     | 28  | 60       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2023 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2023 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2023 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2023 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2023 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+
*/
-- Names of callers
SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2023 AND month = 7 AND day = 28 AND duration <= 60;

/* List:
Suspect List:
+---------+
| Bruce   |
| Diana   |
| Iman    |
| Luca    |
+---------+
Callers:
+---------+
|  name   |
+---------+
| Bruce   |
| Diana   |
+---------+
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |

Accomplice List
Robin (for Bruce)
Philip (for Diana)

Suspect List above
*/
-- What airports are in Fiftyville?
SELECT * FROM airports
   ...> WHERE city = "Fiftyville";
-- | ID = 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
-- What flights left Fiftyville the next day?
SELECT * FROM flights
   ...> WHERE origin_airport_id = 8
   ...> AND year = 2023
   ...> AND month = 7
   ...> AND day = 29;
/*
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 18 | 8                 | 6                      | 2023 | 7     | 29  | 16   | 0      |
| 23 | 8                 | 11                     | 2023 | 7     | 29  | 12   | 15     |
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2023 | 7     | 29  | 9    | 30     |
| 53 | 8                 | 9                      | 2023 | 7     | 29  | 15   | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+

Flight of focus:
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |

*/
-- People on Flight 36
SELECT name FROM people
   ...> JOIN passengers ON passengers.passport_number = people.passport_number
   ...> WHERE flight_id = 36;
/*
+--------+
|  name  |
+--------+
| Doris  |
| Sofia  |
| Bruce  |
| Edward |
| Kelsey |
| Taylor |
| Kenny  |
| Luca   |
+--------+

Thief = Bruce
Left on Flight 36
Accomplice is Robin

City Bruce escacped to is destination airport 4
*/
SELECT city FROM airports
   ...> WHERE id = 4;
-- New York City







