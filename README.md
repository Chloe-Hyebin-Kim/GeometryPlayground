# Geometry Playground

## Project Goal
외부 라이브러리에 의존하지 않고 <br>
**컴퓨터 비전(Computer Vision), 3D Geometry, Camera Calibration, 3D Reconstruction, Photometric Stereo** 등을 <br>
직접 구현하는 것을 목표로 하는 프로젝트. <br>

<br>
최종 목표!!

- Math &Geometry Library (Vector, Matrix, Quaternion, Rotation, Transform, Plane, Ray ...)
- Camera Model
- Calibration Toolkit
- 3D Reconstruction Pipeline
- Photometric Stereo

---

## Current Progress

### Project Structure

```text
GeometryPlayground
│
├── Geometry.Core
│   ├── Math
│   │   ├── DoubleVector
│   │   ├── DoubleMatrix
│   │   └── Utils
│   │
│   └── Geometry
│       ├── Rotation
│       └── Transform
│
└── Geometry.Demo
```

## Implemented

### Math

- Vec2d
- Vec3d
- Mat2d
- Mat3d
- Mat4d

Implemented Features

- Matrix / Vector Arithmetic
- Matrix Multiplication
- Transpose
- Determinant
- Cofactor Matrix
- Adjugate Matrix
- Inverse
- Identity
- IsApprox

### Geometry

#### Rotation

Implemented

- Rodrigues Formula
- Skew Symmetric Matrix
- Rotation Matrix Validation

Verified using

```text
RᵀR = I
det(R) = 1
```

#### Transform

Implemented

- Identity
- Translate
- Rotate
- FromRotationTranslation
- Inverse

Transformation Matrix

```text
[ R11 R12 R13 tx ]
[ R21 R22 R23 ty ]
[ R31 R32 R33 tz ]
[  0   0   0  1 ]
```

Inverse Transformation

```text
[ Rᵀ  -Rᵀt ]
[  0     1 ]
```

## Demo

Implemented demo programs for

- Rodrigues Rotation
- Rotation Matrix Verification
- Transformation Matrix
- Inverse Transformation

Verified using

```text
T × T⁻¹ = I
```

---

## Next Step

```text
Camera
    ↓
Calibration Toolkit
    ↓
3D Reconstruction Pipeline
    ↓
Photometric Stereo
```
