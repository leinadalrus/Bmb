<script setup lang="ts">
defineProps({
    icon: {
        type: String,
        required: true
    }
})
</script>

<template>
    <img v-bind:src="icon" alt="" />
</template>
