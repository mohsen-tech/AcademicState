cpu1: Z1
cpu2: X1
cpu3: Y1
cpu4: Idle
A: 0 B: 1 C: 1
waiting queue: X2 Y2 Z2 Y3 
ending queue: empty!
----------------------------------------------------------------

cpu1: Z1
cpu2: X1
cpu3: Y1
cpu4: X2
A: 0 B: 0 C: 2
waiting queue: Y2 Z2 Y3 
ending queue: Z1 
----------------------------------------------------------------

cpu1: Idle
cpu2: X1
cpu3: Y1
cpu4: X2
A: 1 B: 2 C: 3
waiting queue: Y2 Z2 Y3 
ending queue: Z1 X1 Y1 
----------------------------------------------------------------

cpu1: Y2
cpu2: Z2
cpu3: Y3
cpu4: X2
A: 0 B: 0 C: 0
waiting queue: empty!
ending queue: Z1 X1 Y1 
----------------------------------------------------------------

cpu1: Y2
cpu2: Z2
cpu3: Y3
cpu4: X2
A: 1 B: 1 C: 0
waiting queue: empty!
ending queue: Z1 X1 Y1 X2 
----------------------------------------------------------------

cpu1: Y2
cpu2: Z2
cpu3: Y3
cpu4: Idle
A: 1 B: 1 C: 0
waiting queue: empty!
ending queue: Z1 X1 Y1 X2 
----------------------------------------------------------------

cpu1: Y2
cpu2: Z2
cpu3: Y3
cpu4: Idle
A: 1 B: 1 C: 0
waiting queue: empty!
ending queue: Z1 X1 Y1 X2 
----------------------------------------------------------------

cpu1: Y2
cpu2: Z2
cpu3: Y3
cpu4: Idle
A: 1 B: 2 C: 1
waiting queue: empty!
ending queue: Z1 X1 Y1 X2 Y2 
----------------------------------------------------------------

cpu1: Idle
cpu2: Z2
cpu3: Y3
cpu4: Idle
A: 2 B: 2 C: 2
waiting queue: empty!
ending queue: Z1 X1 Y1 X2 Y2 Z2 
----------------------------------------------------------------

cpu1: Idle
cpu2: Idle
cpu3: Y3
cpu4: Idle
A: 2 B: 3 C: 3
waiting queue: empty!
ending queue: Z1 X1 Y1 X2 Y2 Z2 Y3 
----------------------------------------------------------------

cpu1 Idle-Time: 3
cpu2 Idle-Time: 1
cpu3 Idle-Time: 0
cpu4 Idle-Time: 6