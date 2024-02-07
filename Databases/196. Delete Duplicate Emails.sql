DELETE p2
FROM Person p1, Person p2
Where p1.email = p2.email AND p2.id > p1.id;
