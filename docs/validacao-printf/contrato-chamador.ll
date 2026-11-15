; ModuleID = 'test/unit/printf_bridge_contract.rob'
source_filename = "test/unit/printf_bridge_contract.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

@conststr = private unnamed_addr constant [7 x i8] c"Pronto\0A"
@conststr.1 = private unnamed_addr constant [7 x i8] c"n = %d\0A"

declare i32 @printf(ptr, ptr, i32 zeroext, i32 zeroext) local_unnamed_addr #0

define noundef i32 @main() local_unnamed_addr #0 {
body:
  %sem_valores = alloca [1 x i64], align 8
  %com_valor = alloca [3 x i64], align 8
  store i64 0, ptr %sem_valores, align 8
  store i64 1, ptr %com_valor, align 8
  %elem3 = getelementptr inbounds i8, ptr %com_valor, i32 8
  store i64 1, ptr %elem3, align 8
  %elem4 = getelementptr inbounds i8, ptr %com_valor, i32 16
  store i64 7, ptr %elem4, align 8
  %0 = call i32 @printf(ptr nonnull @conststr, ptr nonnull %sem_valores, i32 zeroext 7, i32 zeroext 1)
  %1 = call i32 @printf(ptr nonnull @conststr.1, ptr nonnull %com_valor, i32 zeroext 7, i32 zeroext 3)
  ret i32 0
}

attributes #0 = { "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
