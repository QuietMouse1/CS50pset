SELECT name
FROM stars JOIN people ON stars.person_id = people.id
WHERE movie_id IN (
SELECT movie_id
FROM stars  JOIN people ON people.id=stars.person_id
WHERE people.id = 
(SELECT id 
FROM people
WHERE birth = 1958 AND name = "Kevin Bacon")
)
AND name != "Kevin Bacon";
