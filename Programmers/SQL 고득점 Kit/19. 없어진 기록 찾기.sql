-- where 조건에 sex_upon_intake
SELECT animal_outs.animal_id ANIMAL_ID, animal_outs.name NAME
from animal_outs
left join animal_ins
on animal_outs.animal_id = animal_ins.animal_id
where sex_upon_intake is null
order by animal_outs.animal_id

--wehre 조건에 intake_condition
select animal_outs.animal_id ANIMAL_ID, animal_outs.name NAME
from animal_outs
left join animal_ins
on animal_outs.animal_id = animal_ins.animal_id
where intake_condition is null
order by animal_outs.animal_id


--where 조건 얘로 해도 맞음, 단 name은 값이 null인 것도 있어서 안됨.
where animal_ins.animal_id is null

-- join 하되, animal_outs에는 있고 ins에는 없는 걸 찾아야 하니까 outs를 기준으로 left join.
-- animal_id 를 기준으로 join 하고, ins에만 있는 게 null 인 row 를 찾아서 id 랑 name 출력 