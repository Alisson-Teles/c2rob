; ModuleID = '/workspace/scratch/e09376208dcf/c2rob/test/unit/out-integration/comparison.validation.rob'
source_filename = "/workspace/scratch/e09376208dcf/c2rob/test/unit/out-integration/comparison.validation.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

define linkonce_odr zeroext i8 @typeid(ptr readonly %0) addrspace(1) #0 {
  %2 = icmp eq ptr %0, null
  br i1 %2, label %3, label %4

3:                                                ; preds = %1
  ret i8 0

4:                                                ; preds = %1
  %5 = load i8, ptr %0, align 1
  ret i8 %5
}

define i32 @contar(i32 %n) addrspace(1) #0 {
  %n1 = alloca i32, align 4
  store i32 %n, ptr %n1, align 4
  %i = alloca i32, align 4
  br label %body

body:                                             ; preds = %0
  br label %while_cond

while_cond:                                       ; preds = %while_body, %body
  %storemerge = phi i32 [ 0, %body ], [ %binop, %while_body ]
  store i32 %storemerge, ptr %i, align 4
  %n3 = load i32, ptr %n1, align 4
  %cmpi = icmp slt i32 %storemerge, %n3
  br i1 %cmpi, label %while_body, label %while_end

while_body:                                       ; preds = %while_cond
  %loadleftv = load i32, ptr %i, align 4
  %binop = add i32 %loadleftv, 1
  br label %while_cond

while_end:                                        ; preds = %while_cond
  %i4 = load i32, ptr %i, align 4
  ret i32 %i4
}

define i32 @main() addrspace(1) #0 {
body:
  ret i32 0
}

attributes #0 = { "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
