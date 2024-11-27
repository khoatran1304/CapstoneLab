## To Show reservation output

Reservation 1 details:
        Yosemite (California)
          Difficulty: moderate
          Duration: 6 day(s)
          $3099.00
Discounted price using points: $2841.00
Reservation 2 details:
        Yellowstone (Wyoming)
          Difficulty: moderate
          Duration: 5 day(s)
          $2599.00
Discounted price using points: $2597.50
Cancelled Reservation 1 details (should be empty):
Reservation not found.


## Test for main file
Assertion passed: res1 == 50001
Assertion passed: res2 == 50002
Assertion passed: res3 == 50003
Reservation 1 details:
        Yosemite (California)
          Difficulty: moderate
          Duration: 6 day(s)
          $3099.00
Discounted price using points: $2841.00
Reservation 2 details:
        Yellowstone (Wyoming)
          Difficulty: moderate
          Duration: 5 day(s)
          $2599.00
Discounted price using points: $2597.50
Reservation 3 details:
        Glacier (Montana)
          Difficulty: unknown
          Duration: 4 day(s)
          $2299.00
Discounted price using points: $2296.00
Cancelled Reservation 2
Cancelled Reservation 2 details (should be empty):
Reservation not found.
Cancelled Reservation 1
Cancelled Reservation 1 details (should be empty):
Reservation not found.
Cancelled Reservation 3
Cancelled Reservation 3 details (should be empty):
Reservation not found.
Assertion passed: reservations.getCount() == 0
Assertion passed: res4 == 50001
Assertion passed: res5 == 50002