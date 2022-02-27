SELECT animal_ins.name NAME, animal_ins.datetime DATETIME
from animal_ins
left join animal_outs
on animal_ins.animal_id = animal_outs.animal_id
where animal_outs.animal_id is null
order by animal_ins.datetime limit 3



-- ins에는 있고 out에는 없는 데이터를 찾아야 함 -> ins 를 기준으로 left join
-- 상위 세개 만 보여주라 했으므로 order by 후 limit